function gridIndex(g, ids) {
    return ids.map((i)=>g.flatMap((c)=>c)[i-1]).join("");
  }
  ////////////////
  const gridIndex = (grid, indices) =>
  indices.map(val => [].concat(...grid)[--val]).join(``);

  //////////
  function gridIndex(grid, indices) {
    const vector = grid.flat()
    return indices.reduce( (acc, el) => acc + vector[el-1], '')
  }