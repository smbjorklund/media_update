import unittest
from selenium import webdriver

from os import readlink
from os.path import basename
import time

class SiteTestCase(unittest.TestCase):

    def setUp(self):
        self.driver = webdriver.Firefox()
        self.driver.implicitly_wait(10)
        self.site_url = 'http://' + basename(readlink('../site'))

    def tearDown(self):
        self.driver.quit()

    def test_homepage(self):
        self.driver.get(self.site_url)
        self.assertEqual(self.driver.title, "Welcome to Universitetet i Bergen | Universitetet i Bergen")
        self.driver.save_screenshot('home.png')

    def test_infopage(self):
        self.driver.get(self.site_url)
        self.driver.find_element_by_link_text('Det juridiske fakultet').click()
        self.driver.find_element_by_link_text('Om fakultetet').click()
        self.driver.save_screenshot('om.png')
        self.driver.find_element_by_link_text('Organisasjonen').click()
        self.driver.save_screenshot('org1.png')
        time.sleep(20)  # give firefox time to update the title
        self.driver.save_screenshot('org2.png');
        time.sleep(30)  # give firefox time to update the title
        self.driver.save_screenshot('org3.png');
        self.assertEqual(self.driver.title, "Organisasjonen | Universitetet i Bergen")
        self.driver.save_screenshot('infopage.png')
