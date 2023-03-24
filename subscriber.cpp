#include "subscriber.hpp"

#include <HelloWorldPubSubTypes.h>
#include <HelloWorldTypeObject.h>

subscriber::subscriber() : type(new HelloWorldPubSubType()) {
  auto dpf = fastdds::DomainParticipantFactory::get_instance();
  participant = dpf->create_participant(0, fastdds::PARTICIPANT_QOS_DEFAULT);

  auto ret = type.register_type(participant);
  if (ret != ReturnCode_t::RETCODE_OK)
    throw std::runtime_error("Failed to register type");

  sub =
      participant->create_subscriber(fastdds::SUBSCRIBER_QOS_DEFAULT, nullptr);
  if (sub == nullptr)
    throw std::runtime_error("Failed to create subscriber");

  topic = participant->create_topic("HelloWorldTopic", type->getName(),
                                    fastdds::TOPIC_QOS_DEFAULT);
  if (topic == nullptr)
    throw std::runtime_error("Failed to create topic");

  std::string expression = "uuid <> %0";
  std::vector<std::string> parameters = {"'1235'"};

  filter_topic = participant->create_contentfilteredtopic(
      "FilteredHelloWorldTopic", topic, expression, parameters);
  if (filter_topic == nullptr)
    throw std::runtime_error("Failed to create filtered topic");
}
