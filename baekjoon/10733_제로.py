k = int(input())
st = []
for _ in range(k):
    tmp = int(input())
    if tmp == 0:
        st.pop()
    else:
        st.append(tmp)
    
print(sum(st))