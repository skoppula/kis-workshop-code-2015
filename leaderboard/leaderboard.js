// Set up a collection to contain player information. On the server,
// it is backed by a MongoDB collection named "players".

Players = new Mongo.Collection("players");

if (Meteor.isClient) {
  Template.leaderboard.helpers({
    players: function () {
      return Players.find({}, { sort: { score: -1, name: 1 } });
    },
    selectedName: function () {
      var player = Players.findOne(Session.get("selectedPlayer"));
      return player && player.name;
    }
  });

  Template.leaderboard.events({
    'click .inc': function () {
      Players.update(Session.get("selectedPlayer"), {$inc: {score: 5}});
    },

    'click .dec': function () {
      Players.update(Session.get("selectedPlayer"), {$inc: {score: -5}});
    }
  });

  Template.player.helpers({
    selected: function () {
      return Session.equals("selectedPlayer", this._id) ? "selected" : '';
    }
  });

  Template.player.events({
    'click': function () {
      Session.set("selectedPlayer", this._id);
    }
  });
}

// On server startup, create some players if the database is empty.
if (Meteor.isServer) {
  Meteor.startup(function () {
    if (Players.find().count() === 0) {
      var names = ["KIS Team - Newton", "KIS Team - Schrodinger", "KIS Team - Curie",
                   "KIS Team - Gauss", "KIS Team - Tesla", "KIS Team - Lovelace", "Team Skanda"];
  	  Players.insert({name: names[0], score: 0});
  	  Players.insert({name: names[1], score: 0});
  	  Players.insert({name: names[2], score: 0});
  	  Players.insert({name: names[3], score: 0});
  	  Players.insert({name: names[4], score: 0});
  	  Players.insert({name: names[5], score: 0});
  	  Players.insert({name: names[6], score: 100});
      //_.each(names, function (name) {
      //Players.insert({
      //   name: name,
      //  score: 0
     // });
     //});
    }
  });
}
