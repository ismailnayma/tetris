#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <set>

class Observer; // Forward declaration

class Observable {
private:
    std::set<Observer *> _observers;

public:
    virtual ~Observable() = default;
    void registerObserver(Observer * observer);
    void unregisterObserver(Observer * observer);
    void notifyObservers() const;
};

#endif // OBSERVABLE_H
