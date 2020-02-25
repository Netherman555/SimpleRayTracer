import pygame

f = open('data.txt', 'r');
image = pygame.Surface((100, 100))

tuples = []
for t in open('data.txt').read().split():
    a, b, c = t.strip('()').split(',')
    tuples.append((float(a), float(b), float(c)))

print(tuples[0])
overallCount = 0

for y in range(100):
    for x in range(100):
        r = tuples[overallCount][0]
        g = tuples[overallCount][1]
        b = tuples[overallCount][2]

        image.set_at((x, y), (r, g, b))

        overallCount += 1

pygame.image.save(image, 'data.png') 
