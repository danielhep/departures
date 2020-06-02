---
home: true
# heroImage: /hero.png
heroText: Headways Departures Display
tagline: When is my bus coming?
actionText: Build One →
actionLink: /guide/
features:
- title: OneBusAway Integration
  details: Connect to a OneBusAway server provided by your transit system, or roll your own using their helpful guides! Works with live or scheduled data.
- title: Advanced Configuration
  details: Configure any combination of stops, routes, and directions. Configure automatic dimming when the lights are off. 
- title: Get Alerts
  details: Be notified instantly of problems or delays that will affect your trip. Exclamation points next to a trip notify you of potential disruptions.
footer: MIT Licensed | Copyright © 2020 Daniel Heppner
---
# What is it?
This is an open source hardware and software project to create a transit departures board similar to those found at train stations and major bus stops. It uses live or scheduled data from the OneBusAway API to show real time predictions of transit vehicles, including whether they are late or early. It can be configured through a web app that allows you to select what routes and stops to display. 

The project uses entirely open source hardware and software so you can build your own. There are many different ways to obtain one:
- Build your own using the parts list.
- Order a kit to build your own from us.
- Order a prebuilt module.
- Order a prebuilt module preconfigured for your transit agency (limited to agencies with OBA servers). 

# How does it work?
Live transit data is usually published in a format called GTFS-RT, while static scheduled data is published in simply GTFS. [One Bus Away](https://onebusaway.org/) is an application that consumes these two data feeds as provided by an agency and converts them into a data feed API that can be consumed by other applications, like this one. 

Currently, many agencies provide their own OneBusAway servers: (not an exhaustive list)
- New York City MTA
- Puget Sound Region, including SoundTransit and King County Metro
- Tampa Bay, FL
- York Region Transit, ON
- Spokane Transit Authority, WA
- San Diego MTS, CA
- DC Metro, DC

If your agency isn't on this list, the OneBusAway project provides instructions on [how you can set up](https://github.com/OneBusAway/onebusaway/wiki/Running-Onebusaway) your own server that can be used with the Headways Departures display. 
