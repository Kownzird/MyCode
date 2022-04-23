const ethers = require('ethers');
const fs = require('fs')

// 生成账号数
let accountNumber = 100;

async function create_new_account() {
    let tmpWallet = ethers.Wallet.createRandom();
    let record=[tmpWallet.privateKey, (await tmpWallet.getAddress()).toString(), tmpWallet.mnemonic.phrase]

    return record;
}

async function main() {
    const FILE_NAME='./secrect.csv'
    let header="PrivateKey,Address,Mnemonic\n";
    fs.writeFile(FILE_NAME,header,err=>{});

    for (let index = 0; index < accountNumber; index++) {
        let record=await create_new_account();
        console.log(record);
        fs.writeFile(FILE_NAME,[record,'\n'],{flag:'a+'},err=>{});

    }
}
main()