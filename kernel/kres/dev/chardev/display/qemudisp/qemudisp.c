// qemudisp.c
// Display controller support.
// #todo: display device for qemu vm. (bochs)
// Created by Fred Nora.


#include <kernel.h>

struct pci_device_d *PCIDeviceQemuDisplay;

int qemu_display_initialize(void)
{
    int Status = -1;

// #test
// Sondando na lista de dispositivos encontrados 
// pra ver se tem algum controlador de display.
// #importante:
// Estamos sondando uma lista que contruimos quando fizemos
// uma sondagem no começo da inicializaçao do kernel.
// #todo: 
// Podemos salvar essa lista.
// #todo
// É uma estrutura para dispositivos pci. (pci_device_d)
// Vamos mudar de nome.


// pci device.
    PCIDeviceQemuDisplay = 
        (struct pci_device_d *) scan_pci_device_list2 ( 
                                    (unsigned char) PCI_CLASSCODE_DISPLAY, 
                                    (unsigned char) PCI_SUBCLASS_NONVGA );

    if ((void *) PCIDeviceQemuDisplay == NULL){
        printk("qemu_display_initialize: PCIDeviceQemuDisplay\n");
        Status = (int) -1;
        goto fail;
    }
    if ( PCIDeviceQemuDisplay->used != TRUE || PCIDeviceQemuDisplay->magic != 1234 ){
        printk ("qemu_display_initialize: PCIDeviceQemuDisplay validation\n");
        Status = (int) -1;
        goto fail;
    }


    // #todo
    // Initialize cntroller.
    // ...

    return 0;
fail:
    return (int) -1;
}

