import tkinter as tk

class App(tk.Frame):
	def __init__(self, master = None):
		super().__init__(master)
		self.pack()
		self.create_widgets()

	def create_widgets(self):
		self.abc = tk.Button(self)
		self.abc["text"] = "Hello World"
		self.abc["command"] = self.talk
		self.abc.pack(side = "top")
		self.quit = tk.Button(self, text = "quit", fg = "red", command = root.destroy)
		self.quit.pack(side = "bottom")

	def talk(self):
		print("Hi")

root = tk.Tk()
app = App(master = root)
app.mainloop()