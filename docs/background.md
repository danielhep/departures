# Why am I making this?
I am a web developer and electrical engineer with an interest in urbanism and transit. For cities, geometry dictates that the only way out of congestion and pollution is with mass transit. I have always wanted to work on projects that make this a more painless, easy experience for people. For those that rely on transit, we know that one of the first things you check before leaving is when the next bus or train is coming so you don't head out too early or too late. This project aims to make that accessing information as simple as glancing at your wall. 

# Why not just use a LCD display?
Using an LCD in some cases may be cheaper, since it is easy to pick up a monitor for $15 and a Raspberry Pi can be had for $35. And it is certainly much more versatile. However, most people would not want to have an ugly computer monitor attached to their wall or on their coffee table on 24/7. The goal of this project is to create something that is subtle enough that you can have it on all the time. It should also appeal to transit nerds in that it resembles the aesthetic of a conventional transit station departures board. 

# Why not just check the status on your phone? 
Most people do this, but it requires opening an app and refreshing the status of your buses. To truly integrate mass transit into your life, it becomes necessary to have that information always accessible. Also, it's cool.

# Challenges
The biggest challenge in this project has been connecting the data sources. Ultimately, I didn't want to reinvent the wheel: Many agencies already provide the data I need in a usable format, but that format differs between agencies. And some agencies don't provide an API at all, they only provide the GTFS-RT feed. Therefore, I settled on OneBusAway's API, since it is open source and can be deployed on existing data even if the agency doesn't host the server themselves. 

Eventually, I plan to integrate a real time server into Headways, which will mean OBA will not longer be needed. 