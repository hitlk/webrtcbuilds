// Revision 19846 is the following, where upstream moved src/webrtc to src/
// https://webrtc.googlesource.com/src/+/92ea95e34af5966555903026f45164afbd7e2088
  #include "rtc_base/thread.h"
  #include "p2p/base/basicpacketsocketfactory.h"
  #include "api/peerconnectioninterface.h"
  #include "api/test/fakeconstraints.h"
  #include "media/engine/webrtcvideocapturerfactory.h"
  #include "api/audio_codecs/builtin_audio_decoder_factory.h"
  #include "api/audio_codecs/builtin_audio_encoder_factory.h"
  #include "modules/audio_device/include/audio_device.h"

int main(int argc, char* argv[]) {
  // something from base
  rtc::Thread* thread = rtc::Thread::Current();

  // something from p2p
  std::unique_ptr<rtc::BasicPacketSocketFactory> socket_factory(
    new rtc::BasicPacketSocketFactory());

  return 0;
}
