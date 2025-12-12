1111111111111111111111111111111111111111111111111111111111111111 
def __mul__(self, other):
        if isinstance(other, (int, float)):
            result = []
            max_len = len(self.wspolczynniki)
            for i in range(1, max_len + 1):
                result.insert(0, self.wspolczynniki[-i]*other)
        if isinstance(other, Wielomian):
            n = len(self.wspolczynniki)
            m = len(other.wspolczynniki)
            result = [0] * (n + m - 1)
            for i in range(n):
                for j in range(m):
                    result[i + j] += self.wspolczynniki[i] * other.wspolczynniki[j]
            return Wielomian(*result)
        return Wielomian(*result)
    def __rmul__(self, other):
        return self.__mul__(other)
mnożenie

    def __add__(self, other):
        if isinstance(other, Wielomian):
            result = []
            max_len = max(len(self.wspolczynniki), len(other.wspolczynniki))
            for i in range(1, max_len + 1):
                a = self.wspolczynniki[-i] if i <= len(self.wspolczynniki) else 0
                b = other.wspolczynniki[-i] if i <= len(other.wspolczynniki) else 0
                result.insert(0, a + b)
            return Wielomian(*result)
        elif isinstance(other, (int, float)):
            result = list(self.wspolczynniki)
            if result:
                result[-1] += other
            else:
                result = [other]
            return Wielomian(*result)

    def __radd__(self, other):
        return self.__add__(other)
 dodawanie


222222222222222222222222222222222222222222222222222222222222222222222222222222222

okienko z przesuwaniem itp

from PySide6.QtWidgets import QApplication, QWidget, QLabel, QPushButton, QVBoxLayout, QHBoxLayout

class MojeOkno(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("MFMGNBHGJF")
        self.setGeometry(300, 300, 300, 300)
        self.show()
        self.nacisniety = 0
    def keyPressEvent(self, event):
        if event.key() == 16777248:
            self.nacisniety=1
    def keyReleaseEvent(self, event):
        if event.key()== 16777234:
            if self.nacisniety==1:
                self.resize(self.width()-10, self.height())
            else:
                self.move(self.x()-10, self.y())
        if event.key()== 16777235:
            if self.nacisniety==1:
                self.resize(self.width(), self.height()-10)
            else:
                self.move(self.x(), self.y()-10)
        if event.key()== 16777236:
            if self.nacisniety==1:
                self.resize(self.width() + 10, self.height())
            else:
                self.move(self.x() + 10, self.y())
        if event.key()== 16777237:
            if self.nacisniety==1:
                self.resize(self.width(), self.height()+10)
            else:
                self.move(self.x(), self.y()+10)
        if event.key() == 16777248:
            self.nacisniety=0
        print("Nacisnieto: ", event.key())
app = QApplication([])
okno = MojeOkno()
app.exec()

okienko dotyczące zamkniecia

from PySide6.QtWidgets import QApplication, QWidget, QMessageBox


class MojeOkno(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Close Event Example")
        self.setGeometry(300, 300, 300, 200)
        self.show()
        self.ignore_close = False  # zmienna decydująca o ignorowaniu eventu

    def closeEvent(self, event):
        if self.ignore_close:
            event.ignore()
            return

        dlg = QMessageBox(self)
        dlg.setWindowTitle("Potwierdzenie")
        dlg.setText("Czy na pewno chcesz zamknąć okno?")
        dlg.setStandardButtons(QMessageBox.Ok | QMessageBox.Cancel)
        result = dlg.exec()
        if result == QMessageBox.Ok:
            event.accept()  # zamknij okno
        else:
            event.ignore()  # ignoruj zamknięcie


app = QApplication([])
okno = MojeOkno()
app.exec()

5555555555555555555555555555555555555555555555555555555
trajektoria

import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp
from matplotlib.animation import FuncAnimation

def funkcja(t, point):
    x, y, vx, vy = point
    if x**2 + y**2 < 1:
        dx = vx
        dy = vy
        dvx = vy
        dvy = -vx
    else:
        dx = vx
        dy = vy
        dvx = 0
        dvy = 0
    return [dx, dy, dvx, dvy]
punkt_start=[-2,0,1,0]
time_span = (0, 10)
time_eval = np.linspace(time_span[0], time_span[1], 500)
res = solve_ivp(funkcja, time_span, punkt_start, t_eval=time_eval)
print(res)
x=res.y[0, :]
y=res.y[1, :]
fig = plt.figure()
ax = fig.add_subplot()
ax.set_xlim(-3, 3)
ax.set_ylim(-3, 3)
ax.set_aspect('equal')
punkt, = ax.plot([], [], 'ro')
linia, = ax.plot([], [], 'b')
def anim(i):
    linia.set_xdata(x[:i + 1])  # wszystkie pozycje od początku do obecnej klatki
    linia.set_ydata(y[:i + 1])
    punkt.set_xdata([x[i]])
    punkt.set_ydata([y[i]])
    return linia, punkt
ani = FuncAnimation(fig, anim, frames=len(x), interval=20, blit=True)
plt.show()


rysowanie przebiegu

import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp #odeint
from matplotlib.animation import FuncAnimation

def pole(t,punkt):
	# GM = 1
	x,vx,y,vy = punkt
	k = 1 / (x**2 + y**2)**1.5
	return [vx,-k*x,vy,-k*y]

res = solve_ivp(pole,(0,10000),(100,0,0,.1),method='DOP853',t_eval=np.linspace(0,10000,1001))
print(res)

plt.plot(0,0,'*')
plt.plot(res.y[0,:],res.y[2,:])
plt.axis('equal')
plt.show()


