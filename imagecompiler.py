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

        if(b == -1000000000.0):
            image.set_at((x, y), (0, 0, 0))

        else:
            if(b * 8 <= -255):
                image.set_at((x, y), (0, 0, 255))

            elif(b * 8 >= 0):
                image.set_at((x, y), (0, 0, 0))

            else:
                image.set_at((x, y), (0, 0, abs(int(b * 8))))

        overallCount += 1

pygame.image.save(image, 'data.png') 
