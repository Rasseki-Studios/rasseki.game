#ifndef EVENTDATA
#define EVENTDATA

class EventData {
public:
    bool Init();
    // void
    Event& getEvent(const str);
    Event& getEvent(coord);
    // more methods coming in future
private:
    void SortEventVector(std::vector<Event>*);
    void PulverizeEvents(std::unordered_map<str, Event>&); //pulverizes events from eventList
    std::vector<Event> ***eventMatrix;
    // std::unique_ptr<Event[][]> eventMatrix;
    std::unordered_map<str, Event> currentEventList;
    // std::unordered_map<str, Event> globalEventList;

};

#endif