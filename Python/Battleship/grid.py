class Cell:
  """Cell definition for filling Grid"""
  def __init__(self):
    #print "Constructing a Cell"
    self.shot = False
    self.ship = None
  def shoot(self, sender):
    """shoot expects the sender's (user) reference"""
    if self.ship == None:
      return False
    if self.ship.navy.user != sender:
      self.shot = True
      self.ship.shoot(self)
    return True

class Grid:
  """Battleship grid definition"""
  def __init__(self):
    print "Constructing a Grid"
