module.exports = function(grunt) {
  var myProxy = grunt.option('proxy');
  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    compass: {
      dist: {
        options: {
          config: 'themes/uib_zen/config.rb',
          bundleExec: true,
          basePath: 'themes/uib_zen/'
        }
      }
    },
    shell: {
      clearCache: {
        options: {
          stderr: false
        },
        command: 'bin/site-drush cc css-js'
      }
    },
    watch: {
      css: {
        files: '**/*.scss',
        tasks: ['compass', 'shell'],
      }
    },
    browserSync: {
      dev: {
        bsFiles: {
          src: 'themes/uib_zen/css/*.css',
        },
        options: {
          watchTask: true,
          proxy: myProxy,
          injectChanges: false
        }
      }
    }
  });

  grunt.loadNpmTasks('grunt-contrib-compass');
  grunt.loadNpmTasks('grunt-shell');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-browser-sync');
  grunt.registerTask('default', ['browserSync', 'watch']);
}
