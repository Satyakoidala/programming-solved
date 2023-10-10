const fn = (arr) => {
    const newArr = arr.flat();

    let sum =0 
    newArr.map((item)=> {
        sum+=item
    })
    console.log(sum);
}

fn([1,2,3,4[5,6]])