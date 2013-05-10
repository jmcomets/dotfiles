#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys
import argparse
import logging
from PIL import Image
from PySFML import sf

# create logger
logger = logging.Logger(__name__)

def _setupLogger(logger):
    # create console handler and set level to debug
    ch = logging.StreamHandler()
    ch.setLevel(logging.DEBUG)

    # create formatter
    format_ = '%(asctime)s - %(name)s - %(levelname)s - %(message)s'
    formatter = logging.Formatter(format_)

    # add formatter to console handler
    ch.setFormatter(formatter)

    # add console handler to logger
    logger.addHandler(ch)

# setup logger
_setupLogger(logger)

def _debug_event(event):
    assert isinstance(event, sf.Event), 'Can only debug sf.Event'
    translate_mapping = {
            sf.Event.Closed              : 'Closed',
            sf.Event.Resized             : 'Resized',
            sf.Event.LostFocus           : 'LostFocus',
            sf.Event.GainedFocus         : 'GainedFocus',
            sf.Event.TextEntered         : 'TextEntered',
            sf.Event.KeyPressed          : 'KeyPressed',
            sf.Event.KeyReleased         : 'KeyReleased',
            sf.Event.MouseWheelMoved     : 'MouseWheelMoved',
            sf.Event.MouseButtonPressed  : 'MouseButtonPressed',
            sf.Event.MouseButtonReleased : 'MouseButtonReleased',
            sf.Event.MouseMoved          : 'MouseMoved',
            sf.Event.MouseEntered        : 'MouseEntered',
            sf.Event.MouseLeft           : 'MouseLeft',
            sf.Event.JoyButtonPressed    : 'JoyButtonPressed',
            sf.Event.JoyButtonReleased   : 'JoyButtonReleased',
            sf.Event.JoyMoved            : 'JoyMoved'}
    event_key = event.Type
    assert event_key in translate_mapping, 'Can only debug valid sf.Event type'
    return "'%s'" % translate_mapping[event_key]

class Painter(sf.Drawable):
    """Painter object, grouping all rendering to a target, also checking
    types (for sf.Drawable subclass), and making sure all objects to draw
    are only drawn to the target once.
    """
    def __init__(self):
        super(Painter, self).__init__()
        logger.debug('Constructing Painter')
        self.drawables = []

    def Render(self, target):
        logger.debug('Rendering Painter at %s' % id(self))
        for d in self.drawables:
            logger.debug('Rendering sf.Drawable at %s' % id(d))
            target.Draw(d)

    def Add(self, drawable):
        if not issubclass(drawable, sf.Drawable):
            raise TypeError
        logger.debug('Adding sf.Drawable at %s to Painter at %s' \
                % (id(drawable), id(self)))
        self.drawables.append(drawable)

    def Remove(self, drawable):
        if not issubclass(drawable, sf.Drawable):
            raise TypeError
        logger.debug('Removing sf.Drawable at %s from Painter at %s' \
                % (id(drawable), id(self)))
        self.drawables.remove(drawable)

def _main_program(spritesheet, out_filename, debug):
    # setup logger level
    if debug:
        logger.debug('Setting log level to DEBUG')
        logger.setLevel(logging.DEBUG)

    # SFML window
    logger.debug('Constructing SFML window')
    window = sf.RenderWindow(sf.VideoMode(800, 600), \
            'AnimationMaker', sf.Style.Close)
    window.SetFramerateLimit(30)

    # 'Painter' object, regroups all rendering
    painter = Painter()

    # main loop
    logger.debug('Entering main loop')
    while window.IsOpened():
        # continuous input
        input_ = window.GetInput()

        # event loop
        logger.debug('Entering event loop')
        event = sf.Event()
        while window.GetEvent(event):
            logger.debug('Handling event %s' % _debug_event(event))
            if event.Type == sf.Event.Closed:
                window.Close()
        logger.debug('Exiting event loop')

        # render group
        logger.debug('Rendering to window')
        window.Clear()
        window.Draw(painter)
        window.Display()

class ValidateImage(argparse.Action):
    def __call__(self, parser, args, value, option_string=None):
        try:
            Image.open(value)
            setattr(args, self.dest, value)
        except IOError:
            raise ValueError("Image '%s' couldn't be loaded" % value)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(
            prog='AnimationMaker',
            description='Create an animation set from a base spritesheet')
    parser.add_argument('-o', '--output', dest='out_filename',
            type=argparse.FileType('w'),
            default=sys.stdout,
            help='Path to output file (existing will be overwritten)')
    parser.add_argument('-v', '--verbose', dest='debug',
            default=False, action='store_true',
            help='Print log information')

    parser.add_argument('spritesheet', action=ValidateImage,
            type=str, help='Path to spritesheet to load')
    parsed_args = parser.parse_args()
    _main_program(**vars(parsed_args))
