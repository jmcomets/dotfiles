class Ship:
  """Ship definition"""
  def __init__(self, cells):
    """__init__ expects the list of prepared cells"""
    self.sunk = False
    self.navy = None
    self.cells = cells
    self.size = len(cells)
    for c in self.cells:
      c.ship = self
  def shoot(self, cell):
    """shoot expects the cell's reference"""
    self.sunk = True
    for c in self.cells:
      if not c.shot:
        self.sunk = False
        break
    if self.sunk:
      self.navy.notify(self)

class Navy:
  """Navy definition"""
  def __init__(self, ships):
    """__init__ expects the list of prepared ships"""
    self.wrecked = False
    self.user = None
    self.ships = ships
    for s in self.ships:
      s.navy = self
  def notify(self, ship):
    """notify expects the sunken ship's reference"""
    self.wrecked = True
    for s in self.ships:
      if not s.sunk:
        self.wrecked = False
        break
