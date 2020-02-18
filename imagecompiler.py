import pygame

f = open('data.txt', 'r');
image = pygame.Surface((100, 100))

tuples = []
for t in open('data.txt').read().split():
    a, b, c = t.strip('()').split(',')
    tuples.append((float(a), float(b), float(c)))

image.fill(tuples[1700])

for y in range(100):
    for x in range(100):
        r = tuples[x*y][0]
        g = tuples[x*y][1]
        b = tuples[x*y][2]

        if(b >= 255):
            b = 255

        if(b <= -255):
            b = 255

        image.set_at((x, y), (0, 0, abs(int(b)), 0))

pygame.image.save(image, 'data.png') 
