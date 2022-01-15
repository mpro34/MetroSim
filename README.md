# MetroSim
Simulate a virtual metro network

## Classes

### Station
Represents a physical train station that trains go to and from.
* Location (x, y) - the physical location of this station in 2D space.
* Name (string) - the unique name representing this station.
* Cost (int) - the cost of traveling through this station.

### Train
Represents a physical train that travels with passengers to and from various stations.
* Number (uuid) - a unique number representing the train.
* PassengerMax (int) - the max number of passengers on this train.
* PassengerCount (int) - the current number of passengers on this train.

### Passenger
Represents a person that takes the trains.
* Name (string) - the name of the person.
* StartLocation (x, y) - the start location of the person in 2D space. (i.e. that person's house)
* EndLocation (x, y) - the goal location of the person in 2D space. (i.e. the grocery store)

### Destination
Represents a physical place in 2D space (i.e. Grocery Store)
* Name (string) - the name of the place / destination.
* Location (x, y) - the location in 2D space of the destination.
* Description (string) - a description of the destination or any other supporting details.

## Methods
`vector<Station> GetRouteTo(Destination d)` - Given a destination, which stations will the Passenger 
have to pass through to get to that destination.

`int GetCostOf(vector<Station> stations)` - Given a list of Stations, what is the cost of traveling.

TODO...
