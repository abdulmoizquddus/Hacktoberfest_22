/**
 * TowerOfHanoi v0.1
 * JavaScript code to create Tower of Hanoi game[0].
 *
 * Copyright (c) 2012 Akeda Bagus (admin@gedex.web.id).
 *
 * Licensed under the MIT (http://www.opensource.org/licenses/mit-license.php) 
 * license.
 *
 * @requires jQuery 1.2+
 * @version 0.1
 * @todo : - Make class and id prefix customizeable.
 *         - Make source peg passable to Game constructor.
 *
 * This code is not a jQuery plugin, but this code needs jQuery and jQuery UI
 * to run. Make sure jQuery and jQuery UI are loaded first before create
 * the Game instance.
 *
 * [0] http://en.wikipedia.org/wiki/Tower_of_Hanoi
 *
 */

var Disc = function(options) {
  this.options = options;
  var opt = this.options;
  this.id = opt.id;
  this.el = jQuery('<div id="disc-' + opt.id +'" title="Disc ' + opt.id +
                   '" class="disc"></div>');
  this.width = opt.width;
  this.margin = opt.margin;
  this.height = opt.height;
  this.el.css({
    'width': this.width,
    'height': this.height,
    'margin-left': this.margin,
    'margin-right': this.margin
  });
  return true;
};

Disc.prototype.getId = function() {
  return this.id;
}

Disc.prototype.getDisc = function() {
  return this.el;
};

var Peg = function(id) {
  // Alphabet for labeling peg.
  this.alpha = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';

  this.discs = [];
  this.container = jQuery('<div class="peg-container"></div>');
  this.peg = jQuery('<div class="peg" id="peg-' + (id+1) + '"></div>');
  this.id = id + 1;
  this.label = jQuery('<div class="peg-label">' + this.alpha[id] + '</div>');
  this.container.append(this.peg);
  this.container.append(this.label);

  return true;
};

Peg.prototype.top = function() {
  return this.discs.length > 0 ? this.discs[0] : null;
};

Peg.prototype.push = function(el) {
  // If discs if not empty
  // put it at 0 index, otherwise
  // push back.
  if (this.discs.length > 0) {
    this.discs.unshift(el);
  } else {
    this.discs.push(el);
  }
};

Peg.prototype.pop = function() {
  var first = this.discs.shift();

  return first;
};

Peg.prototype.getPegContainer = function() {
  return this.container;
};

Peg.prototype.getPeg = function() {
  return this.peg;
};

var Game = function(options) {
  // Default options
  this.options = {
    numOfPegs: 3,
    numOfDiscs: 3,
    container: '#game-container',
    discHeight: 25,
    discMaxWidth: 200,
    destinationPeg: 3
  };

  jQuery.extend(this.options, options);

  // Check all invalid options.
  if (this.options.numOfPegs < 0 || this.options.numOfPegs > 25) {
    this.options.numOfPegs = 3;
  }
  if (this.options.destinationPeg <= 1 ||
      this.options.destinationPeg > this.options.numOfPegs)
  {
    this.options.destinationPeg = this.options.numOfPegs;
  }

  // Current state of the game. Possible values are
  // 'init', 'playing', 'pause', and 'freeze'.
  this.state = 'init';

  // Result of the game. Possible values are 0 for under playing,
  // 1 for win, and -1 for loss.
  this.result = 0;

  // Shortcut for this.options.
  var opt = this.options;

  // Track total steps performed so far.
  this.steps = 0;

  // Minimum number of steps to win the game.
  this.maxSteps = Math.pow(2, this.options.numOfDiscs) - 1;

  // Holds all peg objects.
  this.pegs = [];

  // Container for the game.
  this.container = jQuery(opt.container);

  // Save reference for current object.
  var _this = this;

  // Callback after performing step (moving disc between pegs).
  this.afterStep = this.options.afterStep || function(_this) {};
  // Callback onPause
  this.onPause   = this.options.onPause   || function(_this) {};
  // Callback onFreeze
  this.onFreeze  = this.options.onFreeze  || function(_this) {};
  // Callback afterInit
  this.afterInit = this.options.afterInit || function(_this) {};

  this.createPegs();

  // Source peg which all discs will be placed into.
  var sourcePeg = this.pegs[0];

  this.createDiscs(sourcePeg);

  this.state = 'playing';
  this.afterInit(_this);
};

// Create pegs.
Game.prototype.createPegs = function() {
  for (var i = 0; i < this.options.numOfPegs; i++) {
    this.pegs[i] = new Peg(i);
    this.container.append(this.pegs[i].getPegContainer());

    // Set height based on number of discs.
    this.pegs[i].getPeg().css({
      'min-height': this.options.discHeight*this.options.numOfDiscs
    });

    this._bindDroppableToPeg(this.pegs[i]);
  }
  // Stylize destination peg.
  this.pegs[this.options.destinationPeg-1].
    getPeg().parent().addClass('peg-destination');
}

// Create discs. Peg object which all discs will be in must be
// passed as argument.
Game.prototype.createDiscs = function(sourcePeg) {
  for (var i = 0; i < this.options.numOfDiscs; i++) {
    var disc = new Disc({
      id: i+1,
      width: this.options.discMaxWidth - (this.options.numOfDiscs-i)*20,
      height: this.options.discHeight,
      margin: (this.options.numOfDiscs-i)*10
    });

    // Binds draggable into disc.
    this._bindDraggableToDisc(disc);

    // Push into peg.
    // Since this is the first time populating peg
    // with discs, push MUST be directly called from
    // discs property. Subsequent operation should
    // be using push from peg object.
    sourcePeg.discs.push(disc);

    // Append disc jQuery object into current peg.
    sourcePeg.getPeg().append(disc.getDisc());
    disc.getDisc().css('top', i*this.options.discHeight);
  }

  // Copy the height of peg with full stack,
  // so other pegs have same height.
  var idealPegHeight = sourcePeg.getPeg().height();
  for (var i = 1; i < this.options.numOfPegs; i++) {
    this.pegs[i].getPeg().height(idealPegHeight);
  }

  // Enable top disc on first peg.
  var topDisc = sourcePeg.top().getDisc();
  topDisc.draggable('option', 'disabled', false).addClass('moveable');
}

// Bind droppable to peg.
Game.prototype._bindDroppableToPeg = function (pegObj) {
  // Save reference to object game.
  var _this = this;

  // Droppable handler that pegs have.
  var _pegDroppableHandler = function(e, ui) {
    // All checked conditions should be recorded into
    // new vars rather than checking propery of dynamically changed
    // objects.
    var disc = ui.draggable;
    var disc_id = disc.attr('id');
    var targetPeg = jQuery(this);
        targetPeg = _this.getPegById(targetPeg.attr('id'));
    var isTargetPegEmpty = targetPeg.top() === null ? true : false;
    var targetPegTopDiscId = !isTargetPegEmpty ?
                             targetPeg.top().getDisc().attr('id') : null;

    // Calculate the top position for dropped disc.
    var targetPegTopPosition;
    if (!isTargetPegEmpty) {
      targetPegTopPosition = targetPeg.getPeg().height() - 
        (targetPeg.discs.length+1)*_this.options.discHeight;
    } else {
      targetPegTopPosition =
        (_this.options.numOfDiscs-1)*_this.options.discHeight;
    }

    disc.draggable('option', 'revert', false);
    // Revert when dropped peg has disc on the top <= current disc.
    if (!isTargetPegEmpty && targetPegTopDiscId <= disc_id) {
      disc.draggable('option', 'revert', true); return;
    }

    // Pop the disc from previous peg and push into new target peg.
    var previousPeg = _this.getPegByDiscId(disc.attr('id'));
    targetPeg.push(previousPeg.pop());

    if (!isTargetPegEmpty) {
      // Put at the top of other pegs.
      targetPeg.getPeg().prepend(disc);
      disc.css('top', targetPegTopPosition);
    } else {
      // Put at the bottom of the peg.
      targetPeg.getPeg().append(disc);
      disc.css('top', targetPegTopPosition);
    }

    // Increment steps when disc successfully dropped into new peg.
    _this.steps++;

    for (p in _this.pegs) {
      // Disable dragging to all discs.
      for (d in _this.pegs[p].discs) {
        _this.pegs[p].discs[d].getDisc().draggable(
          'option', 'disabled', true
        ).removeClass('moveable');
      }
      if ( _this.pegs[p].top() !== null ) {
        // Enable draggable for disc on top of the stack.
        _this.pegs[p].top().getDisc().draggable(
          'option', 'disabled', false
        ).addClass('moveable');
      }
    }

    // Executes afterStep callback after disc successfully moved
    // between pegs.
    _this.afterStep(_this);
  }

  pegObj.getPeg().droppable({
    hoverClass: 'peg-over',
    drop: _pegDroppableHandler
  });
};

// Bind draggable to disc.
Game.prototype._bindDraggableToDisc = function (discObj) {
  discObj.getDisc().draggable({
    revert: 'invalid',
    containment: this.container,
    cursor: 'move',
    disabled: true,
    helper: 'clone',
    opacity: 0.35
  });
}

// Get peg object given peg element id
Game.prototype.getPegById = function(attr_id) {
  if (!attr_id) return null;

  var id = attr_id.substring(4) * 1;
  for (var i = 0; i < this.pegs.length; i++) {
    if (this.pegs[i].id == id) return this.pegs[i];
  }
  return null;
};

// Get peg object which contains disc with given disc element id
Game.prototype.getPegByDiscId = function(disc_id) {
  var pegs = this.pegs;
  for (p in pegs) {
    var discs = pegs[p].discs;
    for (d in discs) {
      if (disc_id === discs[d].getDisc().attr('id')) {
        return pegs[p];
      }
    }
  }

  return null;
};

// Get number of steps player has been moved.
Game.prototype.getSteps = function() {
  return this.steps;
};

// Minimum steps required to win the game.
Game.prototype.getMaxSteps = function() {
  return this.maxSteps;
};

// Checks if the player wins the game.
// Returns 1 if wins, 0 not yet, and -1
// for loss.
Game.prototype.isWin = function() {
  if (this.state !== 'playing') return;

  if (this.steps === this.getMaxSteps()) {
    var dest = this.pegs[this.options.destinationPeg-1];
    if (dest.discs.length === this.options.numOfDiscs) {
      this.result = 1;
      return 1;
    }
  } else if (this.steps >= this.getMaxSteps()) {
    if (this.result !== 1) {
      this.result = -1;
      return -1;
    }
    return this.result;
  }
  return 0;
}

// Pause the game. Disable all draggable and droppable handlers. To resume the
// game resume method must be called. The state of the game must be in
// 'playing'.
Game.prototype.pause = function() {
  if (this.state !== 'playing') return;

  for (p in this.pegs) {
    for (d in this.pegs[p].discs) {
      var disc = this.pegs[p].discs[d];
      disc.getDisc().draggable('disable');
    }
    this.pegs[p].getPeg().droppable('disable');
  }

  this.state = 'pause';

  // callback provided onPause
  this.onPause(this);
}

// Resume the game. Enable all droppable handerls to all pegs and draggable
// handler to all top discs. The state of the game must be in 'pause'.
Game.prototype.resume = function() {
  if (this.state !== 'pause') return;

  for (p in this.pegs) {
    // enable disc on top of the peg
    if (this.pegs[p].discs.length > 0) {
      var disc = this.pegs[p].discs[0];
      disc.getDisc().draggable('enable');
    }
    // enable the peg
    this.pegs[p].getPeg().droppable('enable');
  }

  this.state = 'playing';

  // callback provided onResume
  this.onResume(this);
}

// Restart game from the start. It possible to start the game
// with overriden options.
Game.prototype.restart = function(options) {
  // Freeze the game.
  if (this.state !== 'freeze') {
    this.freeze();
  }

  // remove all pegs and discs
  for (var i=0; i<this.options.numOfPegs; i++) {
    var peg = this.pegs[i];
    while (peg.discs.length > 0) {
      peg.pop();
    }
  }
  this.pegs = [];
  this.container.html('');

  // Override options.
  options = options || {};
  jQuery.extend(this.options, options);

  // Create new pegs and discs.
  this.createPegs();
  this.createDiscs(this.pegs[0]);

  // Recalculate minumum steps.
  this.maxSteps = Math.pow(2, this.options.numOfDiscs) - 1;

  // Restart internal states.
  this.steps = 0;
  this.result = 0;
  this.state = 'playing';
}

// Freeze the game. Destroy all draggable
// and dropable handlers.
Game.prototype.freeze = function() {
  if (this.state === 'freeze') return;

  for (p in this.pegs) {
    for (d in this.pegs[p].discs) {
      var disc = this.pegs[p].discs[d];
      disc.getDisc().draggable('destroy').removeClass('moveable');
    }
    this.pegs[p].getPeg().droppable('destroy');
  }

  this.state = 'freeze';

  // callback provided onFreeze
  this.onFreeze(this);
};
