// Revision 19846 is the following, where upstream moved src/webrtc to src/
// https://webrtc.googlesource.com/src/+/92ea95e34af5966555903026f45164afbd7e2088
#if WEBRTC_REVISION_NUMBER >= 19846
  #include "rtc_base/thread.h"
  #include "p2p/base/basicpacketsocketfactory.h"
  #include "api/peerconnectioninterface.h"
  #include "api/test/fakeconstraints.h"
  #include "media/engine/webrtcvideocapturerfactory.h"
  #include "api/audio_codecs/builtin_audio_decoder_factory.h"
  #include "api/audio_codecs/builtin_audio_encoder_factory.h"
  #include "modules/audio_device/include/audio_device.h"
#else
  #include "webrtc/rtc_base/thread.h"
  #include "webrtc/p2p/base/basicpacketsocketfactory.h"
  #include "webrtc/api/peerconnectioninterface.h"
  #include "webrtc/api/test/fakeconstraints.h"
  #include "webrtc/media/engine/webrtcvideocapturerfactory.h"
#endif

int main(int argc, char* argv[]) {
  // something from base
  rtc::Thread* thread = rtc::Thread::Current();

  // something from p2p
  std::unique_ptr<rtc::BasicPacketSocketFactory> socket_factory(
    new rtc::BasicPacketSocketFactory());

  // something from api
  rtc::scoped_refptr<webrtc::PeerConnectionFactoryInterface> peer_connection_factory =
    webrtc::CreatePeerConnectionFactory(
      NULL,
      rtc::Thread::Current(),
      NULL,
      webrtc::AudioDeviceModule::Create(0, webrtc::AudioDeviceModule::kDummyAudio),
      webrtc::CreateBuiltinAudioEncoderFactory(),
      webrtc::CreateBuiltinAudioDecoderFactory(),
      NULL,
      NULL, NULL, NULL);

  // something from api/test
  webrtc::FakeConstraints constraints;

  // something from media/engine
  cricket::WebRtcVideoDeviceCapturerFactory factory;
  std::unique_ptr<cricket::VideoCapturer> capturer = factory.Create(cricket::Device("", 0));

  return 0;
}
