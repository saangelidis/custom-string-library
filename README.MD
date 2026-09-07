### Custom Dynamic String Library

I am making this to learn C

So far I've been researching that there is generally two ways to go about building these strings. 

There is the overhead style, where you build a struct containing the string content and size, which is what I am doing, and the **pascal** strings that contain a header with information inside the string but the string pointer points away from them (and toward the contents of the string).

I was going to originally use a **singly linked list** to implement dynamic strings, however after research I realized that this is a terrible idea memory wise, since with padding, one char would go from 1 byte to 16 bytes.