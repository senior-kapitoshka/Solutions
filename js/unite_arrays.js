function thatUnitesUs(a1, a2, n) {
    return [...new Set([...a1,...a2])].sort().slice(0,n);
  }