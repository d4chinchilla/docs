# Update Authentication

### compress directory
```bash
zip update.zip -r update
```
where `update` is a directory.

### sign the update
```bash
gpg -s update.zip
```
produces a signed file `update.zip.gpg`.

### verify the update
```bash
gpg -o update.zip -d update.zip.gpg
```

### uncompress the update
```bash
unzip update.zip
```

## Setup

### generate a key
```bash
gpg --full-gernerate-key
```
This has already been done for the prototype.

| name | email | password |
|------|-------|----------|
| chinchilla | hmg617@soton.ac.uk | chinchilla |

### export the public key
```bash
gpg -o chinchilla.key --export hm6g17@soton.ac.uk
```

### import the public key
```bash
gpg --import chinchilla.key
gpg --edit-key chinchilla trust
```
Set the trust level to ultimate, `5`. (Press `q` to exit `gpg`.)
