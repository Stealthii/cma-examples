#!/usr/bin/env python


class Scheduler():
    event = ""
    dow = ""
    dow_list = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
                "Friday", "Saturday"]

    def __init__(self, event, dow):
        self.event = event
        self.dow = dow

    def returnindex(self):
        return (self.dow_list.index(self.dow))

    def getevent(self):
        return self.event

    def __str__(self):
        return str(self.event)

    def __cmp__(self, other):
        if (self.returnindex() < other.returnindex()):
            return(-1)
        elif (self.returnindex() == other.returnindex()):
            return(0)
        else:
            return(1)

s = Scheduler("Party at Sara's", "Saturday")
s2 = Scheduler("Party at Harry's", "Friday")

if (s < s2):
    print s.getevent()
elif (s == s2):
    print s.getevent(), s2.getevent()
else:
    print s2.getevent()
