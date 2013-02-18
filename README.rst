Mercurio
========

Mercurio is a set of components designed to run commands in a host. Also known as the deployment machine. It is designed to be pluggable, so you can run arbitrary commands in the host.

The aim of Mercurio is to transmit a message to the host. The other component required is the Mercurio listener.


Mercurio Box
------------

Arduino sketch for to execute commands to to a host via the serial port.

This sketch describes the hardware box used to deploy commands to a host via the serial port.

The listener determines what to do with the values it received.

The sketch sends the targets in the following form::

    target=production


Components
----------

This is the list of components required::

  * An arduino duemilanove or superior.
  * An USB Cable A-B.
  * A LCD display (16 x 2).
  * Two 10k Ohm potentiometers.
  * An analog microswitch.
  * A durable box for holding all the bits together.
