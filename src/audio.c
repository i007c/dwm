
#include <alsa/asoundlib.h>


// ALSA mute/deafen hotkeys
// static snd_ctl_t *ALSA_control;
// static snd_ctl_elem_value_t *ALSA_capture_d;
// static snd_ctl_elem_value_t *ALSA_playback_d;
/*
 * 0 = not mute & not deafen
 * 1 = only mute
 * 2 = only deafen (mic is muted but when undeafen mic will be unmuted too)
 * 3 = mute and deafen
 */
// static short ALSA_status = 0;

/* init ALSA stuff */
// snd_ctl_elem_value_alloca(&ALSA_capture_d);
// snd_ctl_elem_value_alloca(&ALSA_playback_d);

// if (snd_ctl_open(&ALSA_control, "default", 0))
//     die("ALSA not opening.");

// update_sounds(NULL);

    // close ALSA control
    // snd_ctl_close(ALSA_control);

void update_sounds(void) {
    // ALSA_status = arg->i;
//     int input = 0, output = 0;

//     snd_ctl_elem_value_set_numid(ALSA_capture_d, 2);
//     snd_ctl_elem_value_set_numid(ALSA_playback_d, 4);

//     if (snd_ctl_elem_read(ALSA_control, ALSA_capture_d)) {
//         update_sounds(arg);
//         return;
//     }
//     if (snd_ctl_elem_read(ALSA_control, ALSA_playback_d)) {
//         update_sounds(arg);
//         return;
//     }

//     input = snd_ctl_elem_value_get_boolean(ALSA_capture_d, 0);
//     output = snd_ctl_elem_value_get_boolean(ALSA_playback_d, 0);

//     if (ALSA_status == 0 && (input == 0 || output == 0)) {
//         if (!input && !output) ALSA_status = 3;
//         else if (!input) ALSA_status = 1;
//         else if (!output) {
//             ALSA_status = 2;
//             snd_ctl_elem_value_set_boolean(ALSA_capture_d, 0, input ? 0 : 1);
//             if (snd_ctl_elem_write(ALSA_control, ALSA_capture_d) < 0) {
//                 update_sounds(arg);
//                 return;
//             }
//             input = snd_ctl_elem_value_get_boolean(ALSA_capture_d, 0);
//         }
//     }

//     if (!arg) goto update_bar;

//     if (arg->i == 0) {
//         if (!input && !output) {
//             if (ALSA_status == 2) ALSA_status = 3;
//             else ALSA_status = 2;
//             goto update_bar;
//         }
//         if (input && !output) {
//             snd_ctl_elem_value_set_boolean(ALSA_capture_d, 0, 0);
//         } else {
//             snd_ctl_elem_value_set_boolean(ALSA_capture_d, 0, input ? 0 : 1);
//         }
//         if (snd_ctl_elem_write(ALSA_control, ALSA_capture_d) < 0) {
//             update_sounds(arg);
//             return;
//         }
//         input = snd_ctl_elem_value_get_boolean(ALSA_capture_d, 0);
//     } else if (arg->i == 1) {
//         snd_ctl_elem_value_set_boolean(ALSA_playback_d, 0, output ? 0 : 1);
//         if (snd_ctl_elem_write(ALSA_control, ALSA_playback_d) < 0) {
//             update_sounds(arg);
//             return;
//         }
//         output = snd_ctl_elem_value_get_boolean(ALSA_playback_d, 0);
//     }

// update_bar:
//     sprintf(stext, "status: %d", ALSA_status);
//     XStoreName(dpy, root, stext);
//     XFlush(dpy);
}
