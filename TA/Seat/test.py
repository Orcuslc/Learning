from io import FileIO
from unittest import TestCase
from unittest.mock import patch
import seats

class TestCSVParse(TestCase):
	def test_csv_parse_to_stdout(self):
		file = "test.csv"
		expected = 
		with patch("sys.stdout")