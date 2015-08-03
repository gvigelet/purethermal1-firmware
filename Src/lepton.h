#ifndef LEPTON_H_
#define LEPTON_H_

#define VOSPI_FRAME_SIZE (164)
#define LEPTON_IMAGE_SIZE ((60*80)*2)

typedef enum {
  LEPTON_STATUS_OK = 0,
  LEPTON_STATUS_TRANSFERRING = 1,
  LEPTON_STATUS_RESYNC = 2,
} lepton_status;

typedef struct _lepton_buffer {
  uint8_t number;
  lepton_status status;
  uint16_t data[VOSPI_FRAME_SIZE/2 * 60];
} lepton_buffer;

lepton_status complete_lepton_transfer(lepton_buffer *);
lepton_buffer* lepton_transfer(void);

void print_image_binary_background(void);
void lepton_init(void );

#endif
