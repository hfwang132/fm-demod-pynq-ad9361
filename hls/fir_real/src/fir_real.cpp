#include "fir_real.h"

void fir_real(hls::stream<pkt_fdata_t>& out_stream, hls::stream<pkt_fdata_t>& in_stream, fcoef_t *coef, int load_coef)
{
#pragma HLS INTERFACE s_axilite port=load_coef
#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE m_axi depth=64 port=coef offset=slave
#pragma HLS INTERFACE axis port=out_stream
#pragma HLS INTERFACE axis port=in_stream

    static data_t shift_reg[N] = {0};
#pragma HLS ARRAY_PARTITION variable=shift_reg dim=1 complete
    data_t acc;

    int k;

    pkt_fdata_t pkt;

    static data_t coef_buf[N] = {0};
#pragma HLS ARRAY_PARTITION variable=coef_buf dim=1 complete
    if (load_coef) {
    	copy_coef:
    	for (k = 0; k < N; k ++) {
			coef_buf[k] = (coef_t) coef[k];
		}
    }

    top_loop: while (1) {
		TDL:
		for (k = N - 1; k > 0; k --) {
#pragma HLS PIPELINE
			shift_reg[k] = shift_reg[k - D];
		}

		READ:
		for (k = 0; k < D; k ++) {
			in_stream.read(pkt);
			// float to fixed
			pkt.data = (data_t) pkt.data;
			shift_reg[D - k - 1] = pkt.data;
		}

		acc = 0;

		MAC:
		for (k = N - 1; k >= 0; k--) {
#pragma HLS PIPELINE
			acc += shift_reg[k] * coef_buf[k];
		}

		// fixed to float
		pkt.data = (float) acc;

		out_stream.write(pkt);

		if (pkt.last == 1) {
			break;
		}
    }
}
