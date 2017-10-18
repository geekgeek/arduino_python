
#garage class
class Garage:
  def __init__(self):
    self.motorcycles = []
    
  def addMotorcycle(self,themotorcycle):
    self.motorcycles.append(themotorcycle)
  
  def getMotorcycles(self):
    return self.motorcycles

#subclass of garage
class AdvancedGarage(Garage):
  def __init__(self):
    Garage.__init__(self)
    self.motorcycles = []
    self.color = "blue"
    
  def hello2(self):
      return self.color
  

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

#create subclass garage
advgarage = AdvancedGarage()
print(advgarage.hello2())

#add motorcycle to garage
advgarage.addMotorcycle(SuzukiA3)
advgarage.addMotorcycle(bmwAdventureBike)

#print motorcycles in garage
print(advgarage.getMotorcycles()[0].getName())
print(advgarage.getMotorcycles()[0].getSpeed())
print(advgarage.getMotorcycles()[1].getName())
print(advgarage.getMotorcycles()[1].getSpeed())
