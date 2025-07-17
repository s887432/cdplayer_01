#include <cdio/cdio.h>
#include <cdio/audio.h>
#include <cdio/track.h>
#include <stdio.h>

int main(void) {
    CdIo_t* p_cdio = cdio_open(NULL, DRIVER_DEVICE);
    if (!p_cdio) {
        fprintf(stderr, "無法開啟 CD 裝置\n");
        return 1;
    }

    track_t first = cdio_get_first_track_num(p_cdio);
    track_t last = cdio_get_last_track_num(p_cdio);

    for (track_t t = first; t <= last; t++) {
        msf_t start_msf, end_msf;

        if (cdio_get_track_msf(p_cdio, t, &start_msf) != DRIVER_OP_SUCCESS ||
            cdio_get_track_msf(p_cdio, t + 1, &end_msf) != DRIVER_OP_SUCCESS) {
            fprintf(stderr, "無法取得第 %d 軌的 MSF\n", t);
            continue;
        }

        printf("播放軌道 %d (%02d:%02d.%02d)...\n", t,
               start_msf.m, start_msf.s, start_msf.f);

        if (cdio_audio_play_msf(p_cdio, &start_msf, &end_msf) != DRIVER_OP_SUCCESS) {
            fprintf(stderr, "播放失敗 軌道 %d\n", t);
        }

        // 根據實際需要可使用 sleep 或其他等待機制
        // sleep(5);
    }

    cdio_audio_stop(p_cdio);
    cdio_destroy(p_cdio);
    return 0;
}

/*
📌 函式說明
cdio_get_track_msf()：取得某軌道的起始時間（MSF 格式）。
cdio_audio_play_msf(start, end)：播放從 start 到 end 的 CD 音訊區間。
msf_t 結構代表一段時間（Minute, Second, Frame）

⛔ 注意事項
t + 1 若為 CDIO_CDROM_LEADOUT_TRACK（CD 結尾），仍是合法的 cdio_get_track_msf() 輸入。
在播放時建議加入等待或進度控制（如讀取音訊是否仍在播放）。
*/
