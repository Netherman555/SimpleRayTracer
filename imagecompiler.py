f = open('data.txt', 'r');
#image = pygame.Surface((100, 100))

tuples = []
for t in open('data.txt').read().split():
    a = t.strip('()').split(',')
    print(a)

print(tuples)
