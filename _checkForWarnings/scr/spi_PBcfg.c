/********************************************************************
 * Module       : spi                                               *
 * File Name    : spi_PBcfg.c                                       *
 * Description  : Post build configuration for spi driver           *
 * Author       : Mohamed Ashraf                                    *
 ********************************************************************/

#include "spi.h"
/* NOTE: if you decided to use call back function make sure to do some prototyping with extern to those functions */

SPI_ConfigType SPI_1_Cfg = {
                            SPI_8_BIT_DATA_FORMAT,
                            SPI_MSB_BIT_FIRST,
                            SPI_CLK_DIV_64,
                            SPI_MASTER_MODE,
                            SPI_IDLE_HIGH,
                            SPI_WRITE_ON_FIRST_EDGE,
                            NULL_PTR
};

SPI_ConfigType SPI_2_Cfg = {
                            SPI_8_BIT_DATA_FORMAT,
                            SPI_MSB_BIT_FIRST,
                            SPI_CLK_DIV_64,
                            SPI_MASTER_MODE,
                            SPI_IDLE_HIGH,
                            SPI_WRITE_ON_FIRST_EDGE,
                            NULL_PTR
};

