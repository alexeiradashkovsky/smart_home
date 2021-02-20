#include "q_publisher.h"

QueuePublisherClass::QueuePublisherClass(){
}

QueuePublisherClass::~QueuePublisherClass(){
}

void QueuePublisherClass::publish(std::shared_ptr<EventClass> _event) {
    m_events.push(_event);
}

std::shared_ptr<EventClass> QueuePublisherClass::GetEvent() {
    return m_events.pop();
}