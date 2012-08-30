#!/usr/bin/python

import sgmllib, urllib, urlparse

# Web crawler:
#   TODO: synchronize hyperlink and descriptions list

class Parser(sgmllib.SGMLParser):
  "A simple parser class."
  def parse(self, s):
    "Parse the given string 's'."
    self.feed(s)
    self.close()
    self.parsed = True
  def __init__(self, verbose=0):
    "Initialise an object, passing 'verbose' to the superclass."
    sgmllib.SGMLParser.__init__(self, verbose)
    self.hyperlinks = []
    self.descriptions = []
    self.inside_a_element = 0
    self.starting_description = 0
    self.parsed = False
  @staticmethod
  def isAbsoluteLink(link):
    """Tell if link is absolute (true) or relative (false) [static]"""
    return bool(urlparse.urlparse(link).scheme)
  # Redefined methods for sgmllib.SGMLParser
  def start_a(self, attributes):
    "Process a hyperlink and its 'attributes'."
    for name, value in attributes:
      if name == "href":
        self.hyperlinks.append(value)
        self.inside_a_element = 1
        self.starting_description = 1
  def end_a(self):
    "Record the end of a hyperlink."
    self.inside_a_element = 0
  def handle_data(self, data):
    "Handle the textual 'data'."
    if self.inside_a_element:
      if self.starting_description:
        self.descriptions.append(data)
        self.starting_description = 0
      else:
        self.descriptions[-1] += data

"""Functionality added to list. Returns if `item` is in list `l`"""
def in_list(l, item):
  for li in l:
    if item == li:
      return True
  return False

class Logger:
  def __init__(self, fileobject = None):
    self.fileobject = fileobject
  def log(self, content):
    if self.fileobject != None:
      self.fileobject.write(content)
    else:
      print content

class Crawler:
  def __init__(self, parser, logger, max_visits = 1000):
    self.max_visits = max_visits
    self.visited = []
    self.logger = logger
    self.parser = parser
  def visit(self, url):
    if self.overflow():
      print "overflow reached"
      return
    f = urllib.urlopen(url); s = f.read()
    self.parser.parse(s)
    del s; del f
    for i in range(len(self.parser.hyperlinks)):
      a = self.parser.hyperlinks[i]
      d = self.parser.descriptions[i]
      if Parser.isAbsoluteLink(a):
        url = a
      elif a != "/" and a[0] != "#":
        url += a
      self.visited.append(url)
      self.logger.log("[" + d + "](" + url + ")")
      if not in_list(self.visited, url):
        self.visit(url)
  def overflow(self):
    return len(self.visited) > self.max_visits

#c = Crawler(Parser(), Logger())
#c.visit("http://www.python.org")
