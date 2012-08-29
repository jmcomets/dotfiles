class User:
  """User's definition"""
  def __init__(self, navy):
    self.name = ""
    self.lost = False
    self.navy = navy
    self.navy.user = self
  def lose(self):
    self.lost = True
