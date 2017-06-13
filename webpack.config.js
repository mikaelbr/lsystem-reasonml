const path = require('path');

var LiveReloadPlugin = require('webpack-livereload-plugin');

module.exports = {
  entry: './lib/js/src/main.js',
  output: {
    path: path.join(__dirname, 'dist'),
    filename: '[name].js'
  },
  plugins: [new LiveReloadPlugin()]
};
