# yobuzzer
My first Particle Photon firmware.

This firmware publishes 3 functions that can be called from [Particle.io](https://docs.particle.io/guide/getting-started/modes/photon/) API:
* led
* horn
* yo
 
## led
`led` takes a `String` as argument that can be `on`, `off` or `toggle`
### on
will turn on the `D7` led.
### off
will turn the `D7` led off.
### toggle
will switch the `D7` led on if it is currently off and vice-versa.

## horn
will make a buzzer on `D3` to buzz

## yo
takes the same argument as `led`. It will buzz the `horn` and call the `led` function passing the argument that was supplied.
