Mercurio
========

Mercurio is a set of components to run commands in a host. Also known as the deployment machine. It is designed to be plugglable, so you can run whatever you want to in the host.

The other component is the Mercurio listener.


Mercurio Box
------------

Arduino sketch for to deploy commands to to a host via the serial port.

This sketch describes a box used to deploy commands to a host via the serial.

The listener determines what to do with the values it received.

The sketch send the targets in the following form::

    target=production


Components
----------

This is the list of components required::

  * An arduino duemilanove or superior.
  * An USB Cable A-B.
  * A LCD display (16 x 2).
  * Two 10k Ohm potentiometers.
  * An analog microswitch.
  * A durable box for hold all the bits together.
