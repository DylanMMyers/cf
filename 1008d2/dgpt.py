def solve():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    t = int(data[0])  # Number of test cases
    results = []
    idx = 1
    
    for _ in range(t):
        n = int(data[idx])  # Number of gate pairs
        idx += 1
        
        gates = []
        for _ in range(n):
            left_gate, right_gate = data[idx].split(), data[idx + 1].split()
            gates.append((left_gate, right_gate))
            idx += 2
        
        # Initial values
        left_lane = right_lane = 1
        
        for left_gate, right_gate in gates:
            new_left_lane = new_right_lane = 0
            
            # Parse left gate
            if left_gate[0] == '+':
                add_left = int(left_gate[1])
                new_left_lane += add_left
            elif left_gate[0] == 'x':
                mult_left = int(left_gate[1])
                new_left_lane += (mult_left - 1) * left_lane
            
            # Parse right gate
            if right_gate[0] == '+':
                add_right = int(right_gate[1])
                new_right_lane += add_right
            elif right_gate[0] == 'x':
                mult_right = int(right_gate[1])
                new_right_lane += (mult_right - 1) * right_lane
            
            # Allocate optimally between lanes
            total_gain = new_left_lane + new_right_lane
            left_gain = total_gain // 2
            right_gain = total_gain - left_gain
            
            left_lane += left_gain
            right_lane += right_gain
        
        results.append(left_lane + right_lane)
    
    sys.stdout.write('\n'.join(map(str, results)) + '\n')
