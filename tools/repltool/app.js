const repl = require('node:repl');
const { Sample }=require('./lib/sample');

const r = repl.start('> ');
Object.defineProperty(r.context, 'Sample', {
    configurable: false,
    enumerable: true,
    value: Sample
});
