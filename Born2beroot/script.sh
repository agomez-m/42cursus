#!/bin/bash

# Arquitectura
arch=$(uname -a)

# Discos fisicos
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)

# Nucleos VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# Memoria RAM (mega =  megabyte)
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# Memoria del disco (df - diskfilesystem)
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')

# Porcentaje de uso de CPU (vmstat comando de estadisticas) bc calculadora
cpul=$(vmstat 1 4 | tail -1 | awk '{print $15}')
cpu_op=$(echo "100 - $cpul" | bc)
cpu_fin=$(printf "%.1f" $cpu_op)

# Ultimo reinicio (-b flag de la fecha de ultimo)
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE (lsblk - muestra info de todos los disp de bloque, yes si hay 1 o mas l>
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNEXIONS (-ta solo muestra tcp, estab - establecidas)
tcpc=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
ulog=$(users | wc -w)

#  DIRECCION IP Y MAC
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "  Arquitectura del Sistema Operativo: $arch
        Nucleos físicos: $cpuf
        Nucleos Virtuales: $cpuv
        Memoria RAM: $ram_use/${ram_total} ($ram_percent%)
        Memoria del Disco: $disk_use/${disk_total} MB $disk_percent
        Porcentaje de uso CPU: $cpu_fin%
        Ultimo reinicio: $lb
        USO LVM: $lvmu
        Conexiones TCP: $tcpc ESTAB
        Numero de usuarios: $ulog
        Direccion del host y mac: IP $ip MAC ($mac)
        Numero de comandos ejecutados con Sudo: $cmnd cmd"
