class User:
  """User's definition"""
  def __init__(self, navy):
    self.name = ""
    self.navy = navy
    self.navy.user = self
