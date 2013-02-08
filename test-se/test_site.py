import unittest
from selenium import webdriver

from os import readlink
from os.path import basename
from selenium.webdriver.common.keys import Keys

class TestCase(unittest.TestCase):
    def setUp(self):
        self.driver = webdriver.Firefox()
        self.driver.implicitly_wait(10)
        self.site_url = 'http://' + basename(readlink('../site'))

    def tearDown(self):
        self.driver.quit()


class SiteTestCase(TestCase):
    def test_homepage(self):
        self.driver.get(self.site_url)
        self.assertEqual(self.driver.title, "Welcome to Universitetet i Bergen | Universitetet i Bergen")
        self.driver.save_screenshot('home.png')

    def test_infopage(self):
        self.driver.get(self.site_url)
        self.driver.find_element_by_link_text('Det juridiske fakultet').click()
        #self.driver.find_element_by_link_text('Om fakultetet').click()
        #self.driver.save_screenshot('om.png')
        #self.driver.find_element_by_link_text('Organisasjonen').click()
        #self.driver.save_screenshot('org.png')
        #self.assertEqual(self.driver.title, "Organisasjonen | Universitetet i Bergen")

class WebdeskTestCase(TestCase):
    def test_webdesk(self):
        self.driver.get(self.site_url + '/user')
        self.driver.find_element_by_id("edit-name").send_keys("level2")
        self.driver.find_element_by_id("edit-pass").send_keys("admin")
        self.driver.find_element_by_id("edit-submit").submit()
        self.driver.save_screenshot('login.png')

        self.driver.find_element_by_link_text('Add content').click()
        self.driver.find_element_by_id("edit-field-uib-article-type-und").click()
        self.driver.find_element_by_id("edit-field-uib-article-type-und").send_keys(Keys.DOWN)
        self.driver.find_element_by_id("edit-field-uib-article-type-und").send_keys(Keys.ENTER)
        self.driver.find_element_by_id("edit-title").send_keys("En solskinnsdag i Bergen")
        self.driver.find_element_by_id("edit-field-uib-area-und-0-target-id").send_keys("Det juridiske fakultet")
        self.driver.find_element_by_id("edit-field-uib-area-und-0-target-id").send_keys(Keys.DOWN)
        self.driver.find_element_by_id("edit-field-uib-kicker-und-0-value").send_keys("Fint")
        self.driver.find_element_by_id("edit-field-uib-lead-und-0-value").send_keys("November var en meget fin .....")
        self.driver.execute_script("jQuery('#edit-field-uib-text-und-0-value_ifr').contents().find('p').html('Hovedtekst')")
        self.driver.find_element_by_id("edit-field-uib-links-und-0-title").send_keys("Said Berg")
        self.driver.find_element_by_id("edit-field-uib-links-und-0-url").send_keys("http://www.uib.no/personer/Said.Berg")
        self.driver.execute_script("jQuery('#edit-field-uib-fact-box-und-0-value_ifr').contents().find('p').html('Fakta om saken')")
        self.driver.find_element_by_id("edit-submit").submit()
        self.driver.save_screenshot('created_article.png')

        self.driver.find_element_by_link_text('Webdesk').click()
        self.driver.find_element_by_link_text('En solskinnsdag i Bergen').click()
        self.driver.find_element_by_link_text('Edit').click()
        self.driver.find_element_by_id("edit-title").clear()
        self.driver.find_element_by_id("edit-title").send_keys("Regn i Bergen")
        self.driver.find_element_by_id("edit-submit").submit()

        #self.driver.save_screenshot('edit_article.png')
        #self.driver.find_element_by_link_text('Webdesk').click()
        #self.driver.find_element_by_link_text('delete').click()
        #self.driver.find_element_by_id("edit-submit").submit()
        #self.driver.save_screenshot('deleted_article.png')
        self.driver.find_element_by_link_text('Log out').click()
        self.driver.save_screenshot('logged_out.png')
