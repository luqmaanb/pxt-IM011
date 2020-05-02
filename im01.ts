//% color=#444444 icon="\uf07b"
//% groups=['On start', 'Variables', 'Optional']
namespace IM01 {

    //%block="IM01 create folder %u"
    function createFolder(u: string): void {
        mkdir("/sd/" + u)
        return;
    }

    //%block="IM01 size of file %u"
    //%u.defl="log.txt"
    export function sizeOfFile(u: string): number {
        return size("/sd/im01/" + u)
    }

    //%block="IM01 remove file"
    //%u.defl="log.txt"
    export function removeFile(u: string): void {
        remove("/sd/im01/" + u)
        return
    }

    //%block="IM01 file %u exists"
    //%u.defl="log.txt"
    export function fileExists(u: string): boolean {
        return exists("/sd/im01/" + u)
    }

    //%block="IM01 read file %u"
    //%u.defl="log.txt"
    function readFile(u: string): string {
        return ""
    }

    //%block="IM01 overwrite file %u with %v"
    //%u.defl="log.txt"
    export function overwriteFile(u: string, v: string): void {
        file("/sd/im01/" + u, v, "w")
        return
    }

    //%block="IM01 append file %u with %v"
    //%u.defl="log.txt"
    export function appendFile(u: string, v: string): void {
        file("/sd/im01/" + u, v, "a")
        return
    }

    //%block="IM01 append file %u with line %v"
    //%u.defl="log.txt"
    export function appendFileLine(u: string, v: string): void {
        file("/sd/im01/" + u, v + "\n", "a")
        return
    }

    //%shim=im01::_mkdir
    function mkdir(u: string): void {
        return
    }

    //%shim=im01::_remove
    function remove(u: string): void {
        return
    }

    //%shim=im01::_file
    function file(u: string, v: string, x: string): boolean {
        return true
    }

    //%shim=im01::_size
    function size(u: string): number {
        return 1
    }

    //%shim=im01::_exists
    function exists(u: string): boolean {
        return true
    }

    //%shim=im01::_read
    function read(u: string): string {
        return ""
    }

    createFolder("im01")
}