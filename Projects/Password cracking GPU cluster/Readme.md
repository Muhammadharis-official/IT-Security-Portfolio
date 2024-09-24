BUILDING A MULTI-GPU CLUSTER FOR HASHCAT USING LINUX AND NVIDIA
Creating a multi-GPU cluster for Hashcat password cracking can be cost-effective by selecting a mix of budget-friendly GPUs that offer a decent hash rate.
In recent times, driven by the AI boom and previously by the cryptocurrency surge, there has been significant price inflation and exploitation by GPU manufacturers, particularly NVIDIA, for graphics cards capable of large-scale password cracking.
This guide demonstrates how to construct a multi-GPU cluster that provides a superior price/performance ratio compared to investing in a single high-end GPU.
My objective is to optimize both cost and risk. Running extensive password hash cracking on a GPU can lead to premature wear, but using budget GPUs minimizes replacement costs, making it a more economical choice.
Aside from the GPUs and their PCI-E risers, I sourced all other components second-hand from online marketplaces, as new parts are not necessary.
I utilized five GPUs for this setup, with the potential to add a sixth. This cluster is self-sufficient and does not require a monitor since I employ an HDMI screen as part of the configuration.
NOTE: This cluster is also suitable for machine learning and other CUDA programming tasks!
REQUIREMENTS
5-6 NVIDIA GeForce 1650 GTX GPUs - Links available on Amazon and Best Buy. I purchased these on sale for $139.99 each during Labor Day and Thanksgiving sales in the USA. The total cost was under $900, including taxes, which is less than the price of a new RTX 4090 GPU, typically over $1600. While the RTX 4090 offers exceptional performance if your budget allows it.
Refurbished HP Z840 with 128GB RAM and 1TB SSDs from eBay for around $460. Any barebones PC can work, but having at least 32GB RAM and 6+ GPU slots is beneficial. Cryptocurrency miners often use motherboards with 12 GPU slots; however, these may lack sufficient RAM or powerful CPUs, limiting your cluster's versatility for tasks like machine learning or password cracking.
Kali Linux or Ubuntu 22.04 LTS
NVIDIA drivers: I am currently using NVIDIA-Linux-x86_64-535.146.02.run from NVIDIA for Linux.
6 GPU Risers: Necessary for utilizing various PCI-E slots with PCI-E x16 GPUs.
Crypto mining rig hardware or a second-hand rig from Facebook Marketplace; I acquired mine for $30 along with fans that were not used.
EVGA 1500W Power Supply or a functional pre-owned unit; I purchased mine second-hand for $40.
Extruded Aluminum if you wish to construct the entire frame from scratch.
Aluminum rail accessories: Required for assembling some parts of the rig together if your design resembles mine.
Brass Standoff screws: Used to secure the GPUs to the rails.
Tap and Die Set: Needed for threading small holes for your standoff screws.
Drill and drill bits: I already owned these tools; you can find affordable drills on Facebook Marketplace and buy new drill bits.
HDMI 7” screen: To serve as a touchscreen monitor.
Metric Allen wrench set
Phillips Screwdriver, Pliers
In total, combining new and pre-owned equipment, my expenditure was about $1550. Purchasing everything new could increase costs by approximately $500, which could instead be allocated towards acquiring additional GPUs or an RTX 4090 without needing anything else!
SETUP
In Figure 1, you can see a typical cryptocurrency mining rig featuring seven large fans, a substantial power supply exceeding 1500W, space designated for mounting the motherboard (highlighted in yellow), and a broad beam for securing the GPUs. My pre-owned frame still has some screws near the bottom edge of the yellow rectangle on the beam.
Before modifying the frame, ensure you test your hardware to confirm that all components are functioning correctly—this includes checking your risers and GPUs. Figure 2 illustrates my hardware testing process.
I disassembled the entire rig into its components and identified suitable aluminum legs and corresponding screws to create a flat structure as depicted in Figure 3. If you're not using a pre-designed frame, you can utilize extruded aluminum to build your own structure from scratch. Drilling holes and using the tap-and-die set will be necessary to thread holes for screws—both standoff screws and others needed for assembling legs together. Aluminum rail accessories can also be used to connect legs to one another.
I drilled small 1/8” holes for M3 screws to secure the GPU risers as shown in Figure 3. Ensure precise measurements; I used painter's tape on the aluminum legs to mark positions before drilling to avoid errors.
After installing all risers securely, I added one GPU per riser. In my setup shown in Figure 4, I utilized only four GPUs. Although I could have included a fifth riser space, upgrading to larger GPUs might restrict airflow if not properly planned. However, you may design yours more effectively than mine.
Now refer to the documentation of your EVGA power supply and GPU risers or consult YouTube videos to correctly connect power cables to the GPU cards, risers, and other system components.
After all connections are made, I constructed a small front-facing tower to attach the 7” HDMI screen at the front of the GPU rack as shown in Figure 6. The HDMI cable from this screen connects to an internal GPU in the computer. The screen also features touchscreen capabilities powered via USB-C cable connected to a USB-3 port on the computer.
LINUX AND DRIVERS
I opted for Kali Linux on the HP Z840 as it functions seamlessly out of the box; however, Ubuntu 22.04 LTS is also an option if your focus is beyond password cracking. Installing Kali Linux follows standard procedures outlined in various resources.
Once Kali Linux is installed, download the appropriate NVIDIA drivers from NVIDIA's website by selecting your specifications in their form. It’s best to perform this directly on the computer being set up using modern browsers like Firefox or Google Chrome.
The form fields specific to GTX 1650 are displayed in Figure 7. After hitting search on this form, you will receive access to the most recent driver file from NVIDIA; at this time, I downloaded NVIDIA-Linux-x86_64-535.146.02.run (indicating driver version 535.146.02). Execute this file as root using:
bash
root$ ./NVIDIA-Linux-x86_64-535.146.02.run

Upon completion of this installation process, proceed with installing CUDA SDK using:
bash
root$ wget https://developer.download.nvidia.com/compute/cuda/12.3.2/local_installers/cuda_12.3.2_545.23.08_linux.run
root$ sudo sh cuda_12.3.2_545.23.08_linux.run

bash
root$ sh cuda_12.3.2_545.23.08_linux.run.

Result:
$ /usr/local/cuda/extras/demo_suite/deviceQuery
./deviceQuery Starting...

 CUDA Device Query (Runtime API) version (CUDART static linking)

Detected 5 CUDA Capable device(s)

Device 0: "NVIDIA GeForce GTX 1650"
  CUDA Driver Version / Runtime Version          12.2 / 12.2
  CUDA Capability Major/Minor version number:    7.5
  Total amount of global memory:                 3904 MBytes (4093509632 bytes)
  (14) Multiprocessors, ( 64) CUDA Cores/MP:     896 CUDA Cores
  GPU Max Clock rate:                            1590 MHz (1.59 GHz)
  Memory Clock rate:                             6001 Mhz
  Memory Bus Width:                              128-bit
  L2 Cache Size:                                 1048576 bytes
  Maximum Texture Dimension Size (x,y,z)         1D=(131072), 2D=(131072, 65536), 3D=(16384, 16384, 16384)
  Maximum Layered 1D Texture Size, (num) layers  1D=(32768), 2048 layers
  Maximum Layered 2D Texture Size, (num) layers  2D=(32768, 32768), 2048 layers
  Total amount of constant memory:               65536 bytes
  Total amount of shared memory per block:       49152 bytes
  Total number of registers available per block: 65536
  Warp size:                                     32
  Maximum number of threads per multiprocessor:  1024
  Maximum number of threads per block:           1024
  Max dimension size of a thread block (x,y,z): (1024, 1024, 64)
  Max dimension size of a grid size    (x,y,z): (2147483647, 65535, 65535)
  Maximum memory pitch:                          2147483647 bytes
  Texture alignment:                             512 bytes
  Concurrent copy and kernel execution:          Yes with 3 copy engine(s)
  Run time limit on kernels:                     Yes
  Integrated GPU sharing Host Memory:            No
  Support host page-locked memory mapping:       Yes
  Alignment requirement for Surfaces:            Yes
  Device has ECC support:                        Disabled
  Device supports Unified Addressing (UVA):      Yes
  Device supports Compute Preemption:            Yes
  Supports Cooperative Kernel Launch:            Yes
  Supports MultiDevice Co-op Kernel Launch:      Yes
  Device PCI Domain ID / Bus ID / location ID:   0 / 2 / 0
  Compute Mode:
     < Default (multiple host threads can use ::cudaSetDevice() with device simultaneously) >

Device 1: "NVIDIA GeForce GTX 1650"
  CUDA Driver Version / Runtime Version          12.2 / 12.2
  CUDA Capability Major/Minor version number:    7.5
  Total amount of global memory:                 3902 MBytes (4091150336 bytes)
  (14) Multiprocessors, ( 64) CUDA Cores/MP:     896 CUDA Cores
  GPU Max Clock rate:                            1590 MHz (1.59 GHz)
  Memory Clock rate:                             6001 Mhz
  Memory Bus Width:                              128-bit
  L2 Cache Size:                                 1048576 bytes
  Maximum Texture Dimension Size (x,y,z)         1D=(131072), 2D=(131072, 65536), 3D=(16384, 16384, 16384)
  Maximum Layered 1D Texture Size, (num) layers  1D=(32768), 2048 layers
  Maximum Layered 2D Texture Size, (num) layers  2D=(32768, 32768), 2048 layers
  Total amount of constant memory:               65536 bytes
  Total amount of shared memory per block:       49152 bytes
  Total number of registers available per block: 65536
  Warp size:                                     32
  Maximum number of threads per multiprocessor:  1024
  Maximum number of threads per block:           1024
  Max dimension size of a thread block (x,y,z): (1024, 1024, 64)
  Max dimension size of a grid size    (x,y,z): (2147483647, 65535, 65535)
  Maximum memory pitch:                          2147483647 bytes
  Texture alignment:                             512 bytes
  Concurrent copy and kernel execution:          Yes with 3 copy engine(s)
  Run time limit on kernels:                     Yes
  Integrated GPU sharing Host Memory:            No
  Support host page-locked memory mapping:       Yes
  Alignment requirement for Surfaces:            Yes
  Device has ECC support:                        Disabled
  Device supports Unified Addressing (UVA):      Yes
  Device supports Compute Preemption:            Yes
  Supports Cooperative Kernel Launch:            Yes
  Supports MultiDevice Co-op Kernel Launch:      Yes
  Device PCI Domain ID / Bus ID / location ID:   0 / 3 / 0
  Compute Mode:
     < Default (multiple host threads can use ::cudaSetDevice() with device simultaneously) >

Device 2: "NVIDIA GeForce GTX 1650"
  CUDA Driver Version / Runtime Version          12.2 / 12.2
  CUDA Capability Major/Minor version number:    7.5
  Total amount of global memory:                 3904 MBytes (4093509632 bytes)
  (14) Multiprocessors, ( 64) CUDA Cores/MP:     896 CUDA Cores
  GPU Max Clock rate:                            1590 MHz (1.59 GHz)
  Memory Clock rate:                             6001 Mhz
  Memory Bus Width:                              128-bit
  L2 Cache Size:                                 1048576 bytes
  Maximum Texture Dimension Size (x,y,z)         1D=(131072), 2D=(131072, 65536), 3D=(16384, 16384, 16384)
  Maximum Layered 1D Texture Size, (num) layers  1D=(32768), 2048 layers
  Maximum Layered 2D Texture Size, (num) layers  2D=(32768, 32768), 2048 layers
  Total amount of constant memory:               65536 bytes
  Total amount of shared memory per block:       49152 bytes
  Total number of registers available per block: 65536
  Warp size:                                     32
  Maximum number of threads per multiprocessor:  1024
  Maximum number of threads per block:           1024
  Max dimension size of a thread block (x,y,z): (1024, 1024, 64)
  Max dimension size of a grid size    (x,y,z): (2147483647, 65535, 65535)
  Maximum memory pitch:                          2147483647 bytes
  Texture alignment:                             512 bytes
  Concurrent copy and kernel execution:          Yes with 3 copy engine(s)
  Run time limit on kernels:                     Yes
  Integrated GPU sharing Host Memory:            No
  Support host page-locked memory mapping:       Yes
  Alignment requirement for Surfaces:            Yes
  Device has ECC support:                        Disabled
  Device supports Unified Addressing (UVA):      Yes
  Device supports Compute Preemption:            Yes
  Supports Cooperative Kernel Launch:            Yes
  Supports MultiDevice Co-op Kernel Launch:      Yes
  Device PCI Domain ID / Bus ID / location ID:   0 / 4 / 0
  Compute Mode:
     < Default (multiple host threads can use ::cudaSetDevice() with device simultaneously) >

Device 3: "NVIDIA GeForce GTX 1650"
  CUDA Driver Version / Runtime Version          12.2 / 12.2
  CUDA Capability Major/Minor version number:    7.5
  Total amount of global memory:                 3904 MBytes (4093509632 bytes)
  (14) Multiprocessors, ( 64) CUDA Cores/MP:     896 CUDA Cores
  GPU Max Clock rate:                            1590 MHz (1.59 GHz)
  Memory Clock rate:                             6001 Mhz
  Memory Bus Width:                              128-bit
  L2 Cache Size:                                 1048576 bytes
  Maximum Texture Dimension Size (x,y,z)         1D=(131072), 2D=(131072, 65536), 3D=(16384, 16384, 16384)
  Maximum Layered 1D Texture Size, (num) layers  1D=(32768), 2048 layers
  Maximum Layered 2D Texture Size, (num) layers  2D=(32768, 32768), 2048 layers
  Total amount of constant memory:               65536 bytes
  Total amount of shared memory per block:       49152 bytes
  Total number of registers available per block: 65536
  Warp size:                                     32
  Maximum number of threads per multiprocessor:  1024
  Maximum number of threads per block:           1024
  Max dimension size of a thread block (x,y,z): (1024, 1024, 64)
  Max dimension size of a grid size    (x,y,z): (2147483647, 65535, 65535)
  Maximum memory pitch:                          2147483647 bytes
  Texture alignment:                             512 bytes
  Concurrent copy and kernel execution:          Yes with 3 copy engine(s)
  Run time limit on kernels:                     Yes
  Integrated GPU sharing Host Memory:            No
  Support host page-locked memory mapping:       Yes
  Alignment requirement for Surfaces:            Yes
  Device has ECC support:                        Disabled
  Device supports Unified Addressing (UVA):      Yes
  Device supports Compute Preemption:            Yes
  Supports Cooperative Kernel Launch:            Yes
  Supports MultiDevice Co-op Kernel Launch:      Yes
  Device PCI Domain ID / Bus ID / location ID:   0 / 132 / 0
  Compute Mode:
     < Default (multiple host threads can use ::cudaSetDevice() with device simultaneously) >

Device 4: "NVIDIA GeForce GTX 1650"
  CUDA Driver Version / Runtime Version          12.2 / 12.2
  CUDA Capability Major/Minor version number:    7.5
  Total amount of global memory:                 3904 MBytes (4093509632 bytes)
  (14) Multiprocessors, ( 64) CUDA Cores/MP:     896 CUDA Cores
  GPU Max Clock rate:                            1590 MHz (1.59 GHz)
  Memory Clock rate:                             6001 Mhz
  Memory Bus Width:                              128-bit
  L2 Cache Size:                                 1048576 bytes
  Maximum Texture Dimension Size (x,y,z)         1D=(131072), 2D=(131072, 65536), 3D=(16384, 16384, 16384)
  Maximum Layered 1D Texture Size, (num) layers  1D=(32768), 2048 layers
  Maximum Layered 2D Texture Size, (num) layers  2D=(32768, 32768), 2048 layers
  Total amount of constant memory:               65536 bytes
  Total amount of shared memory per block:       49152 bytes
  Total number of registers available per block: 65536
  Warp size:                                     32
  Maximum number of threads per multiprocessor:  1024
  Maximum number of threads per block:           1024
  Max dimension size of a thread block (x,y,z): (1024, 1024, 64)
  Max dimension size of a grid size    (x,y,z): (2147483647, 65535, 65535)
  Maximum memory pitch:                          2147483647 bytes
  Texture alignment:                             512 bytes
  Concurrent copy and kernel execution:          Yes with 3 copy engine(s)
  Run time limit on kernels:                     Yes
  Integrated GPU sharing Host Memory:            No
  Support host page-locked memory mapping:       Yes
  Alignment requirement for Surfaces:            Yes
  Device has ECC support:                        Disabled
  Device supports Unified Addressing (UVA):      Yes
  Device supports Compute Preemption:            Yes
  Supports Cooperative Kernel Launch:            Yes
  Supports MultiDevice Co-op Kernel Launch:      Yes
  Device PCI Domain ID / Bus ID / location ID:   0 / 133 / 0
  Compute Mode:

deviceQuery, CUDA Driver = CUDART, CUDA Driver Version = 12.2, CUDA Runtime Version = 12.2, NumDevs = 5, Device0 = NVIDIA GeForce GTX 1650, Device1 = NVIDIA GeForce GTX 1650, Device2 = NVIDIA GeForce GTX 1650, Device3 = NVIDIA GeForce GTX 1650, Device4 = NVIDIA GeForce GTX 1650
Result = PASS