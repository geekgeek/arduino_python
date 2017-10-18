#garage class
class Garage:
  def __init__(self):
    self.motorcycles = []
    
  def addMotorcycle(self,themotorcycle):
    self.motorcycles.append(themotorcycle)
  
  def getMotorcycles(self):
    return self.motorcycles

#motorcycle class  
class Motorcycle:
  def __init__(self,theName):
      self.theName = theName
      self.engine = "2 cylinder"
      self.speed = 200

  def getSpeed(self):
      return self.speed
      
  def setSpeed(self,newspeed):
      self.speed = newspeed
  
  def getName(self):
      return self.theName
 
#create motorcycles     
SuzukiA3 = Motorcycle("suzuki a3")
bmwAdventureBike = Motorcycle("bmw adventure bike")

bmwAdventureBike.setSpeed(500)

#create garage
biggarage = Garage()

#add motorcycle to garage
biggarage.addMotorcycle(SuzukiA3)
biggarage.addMotorcycle(bmwAdventureBike)

#print motorcycles in garage
print(biggarage.getMotorcycles()[0].getName())
print(biggarage.getMotorcycles()[0].getSpeed())
print(biggarage.getMotorcycles()[1].getName())
print(biggarage.getMotorcycles()[1].getSpeed())
