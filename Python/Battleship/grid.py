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
  def __init__(self, rows, cols):
    #print "Constructing a Grid"
    self.rows = rows
    self.cols = cols
    self.grid = []
    for i in range(rows):
      row = []
      for j in range(cols):
        row.append(Cell())
      self.grid.append(row)
  def __str__(self):
    s = "Grid:\n"
    for i in range(self.rows):
      s += "| "
      for j in range(self.cols):
        s += str(int(self.grid[i][j].shot)) + " |"
      s += "\n"
    return s
