from pydub import AudioSegment
import os, sys, re

class Cutter:
	def __init__(path):
		[self.sound_name, self.sound_format] = os.path.basename(path).split('.')
		self.sound_path = os.path.dirname(path)
		wav_path = self.sound_path+self.sound_name+'.wav'
		switcher = {
			'mp3': lambda x: AudioSegment.from_mp3(x).export(wav_path, format='wav')
			'ogg': lambda x: AudioSegment.from_ogg(x).export(wav_path, format='wav')
			'raw': lambda x: AudioSegment.from_raw(x).export(wav_path, format='wav')
			'wav': lambda x: 0
		}
		func = switcher.get(self.sound_format, lambda: 'File Type Not Supported.')
		func(path)
		

