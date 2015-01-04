// Set up a collection to contain player information. On the server,
// it is backed by a MongoDB collection named "players".

Players = new Mongo.Collection("players");

if (Meteor.isClient) {
  Template.leaderboard.players = function () {
    return Players.find({}, {sort: {score: -1, name: 1}});
  };

  Template.leaderboard.selected_name = function () {
    var player = Players.findOne(Session.get("selected_player"));
    return player && player.name;
  };

  Template.player.selected = function () {
    return Session.equals("selected_player", this._id) ? "selected" : '';
  };

  Template.leaderboard.events({
    'click button.inc': function () {
      Players.update(Session.get("selected_player"), {$inc: {score: 5}});
    }
  });

  Template.player.events({
    'click': function () {
      Session.set("selected_player", this._id);
    }
  });
}

// On server startup, create some players if the database is empty.
if (Meteor.isServer) {
  Meteor.startup(function () {
    if (Players.find().count() === 0) {
      var names = ["Gru",
                   "Vector",
                   "Dr. Nefario",
                   "Edith",
                   "Agnes",
                   "Miss Hattie",
                   "Mr. Perkins",
                   "Margo"];
      Players.insert(names[0], 0);
      Players.insert(names[1], 0);
      Players.insert(names[2], 0);
      Players.insert(names[3], 0);
      Players.insert(names[4], 0);
      Players.insert(names[5], 0);
      Players.insert(names[6], 0);
      Players.insert(names[7], 0);
      //for (var i = 0; i < names.length; i++)
        //Players.insert({name: names[i], score: 0});
    }
  });
}
