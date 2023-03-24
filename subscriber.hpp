#ifndef EPROSIMA_TEST_SUBSCRIBER_HPP
#define EPROSIMA_TEST_SUBSCRIBER_HPP

#include <HelloWorld.h>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>

namespace fastdds = eprosima::fastdds::dds;

class subscriber {
public:
  subscriber();

private:
  fastdds::DomainParticipant *participant;
  fastdds::Topic *topic;
  fastdds::ContentFilteredTopic *filter_topic;
  fastdds::Subscriber *sub;
  fastdds::DataReader *datareader;
  fastdds::TypeSupport type;

  HelloWorld msg;
};

#endif // EPROSIMA_TEST_SUBSCRIBER_HPP
